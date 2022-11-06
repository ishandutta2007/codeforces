module Main where
import Control.Monad
import Data.Char

countSeg :: String -> Integer
countSeg [] = 0
countSeg (a:[]) = 1
countSeg (a:b:c)
  |isAlpha a==isAlpha b =   countSeg(b:c)
  |otherwise            = 1+countSeg(b:c)

alphaToInt :: String -> Int -> Int
alphaToInt [] sum = sum
alphaToInt (a:b) sum = alphaToInt b (sum*26+ord a-64)

intToAlpha :: Int -> String
intToAlpha n
  | n<26      = chr (65+n) : []
  | otherwise = (intToAlpha (div n 26 - 1)) ++ ((chr (65+(mod n 26))):[]) 

splitAll :: String -> [String]
splitAll [] = []
splitAll s = do
  let (p:q) = s
  if isAlpha p then
    let (a,b) = splitAt (length $takeWhile isAlpha s) s in
    a:splitAll b
  else
    let (a,b) = splitAt (length $takeWhile (not.isAlpha) s) s in
    a:splitAll b

solve :: Integer -> IO ()
solve n = do
    if (n==0) then return ()
    else do
        line <- getLine
        if countSeg line == 2 then 
            let (a:b:_)=splitAll line in
            putStr $"R"++b++"C"++(show $alphaToInt a 0)++"\n"
        else
            let (a:b:c:d:_)=splitAll line in
            putStr $intToAlpha (((read::String->Int) d)-1)++b++"\n"
        solve (n-1)

main = do
  buf <- getLine
  let (n:_) = map (read::String->Integer) (buf:[])
  solve n