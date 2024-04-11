import Data.Char
import Data.List
import Data.Int
import Data.Maybe
import qualified Data.ByteString.Char8 as B

maximizePairs :: [Int] -> [Int]
maximizePairs = snd . foldr step ((0 :: Int, 0 :: Int), []) . group . sort 
    where
        step xs ((lastVal, cnt), list) 
            | length xs `mod` 2 == 0 || lastVal /= h + 1 || cnt == 0 = 
                let add = if lastVal == h + 1 then cnt else 0
                in
                    ((h, max add (length xs `mod` 2)), replicate pairs h ++ list)
            | otherwise = 
                ((h, 0), replicate (pairs + 1) h ++ list)
            where
                pairs = length xs `div` 2
                h = head xs
                
groupPairs :: [Int] -> Int64
groupPairs [] = 0
groupPairs [x] = 0
groupPairs (x:y:xys) = fromIntegral x * fromIntegral y + groupPairs xys
         
readIntList :: IO [Int]
readIntList = do
    _ <- B.getLine
    line <- B.getLine
    let res = map (fst . fromJust . B.readInt) $ B.words line
    return res
    
main = do
    a <- readIntList
    print $ groupPairs . reverse . maximizePairs $ a