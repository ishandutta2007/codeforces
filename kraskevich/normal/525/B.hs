import Data.Char
import Data.List
import Data.Int
import Data.Maybe
import Control.Monad
import qualified Data.Sequence as Seq
import Data.Foldable(toList)
import qualified Data.ByteString.Char8 as B

readInt :: IO Int
readInt = head `liftM` readIntList
         
readIntList :: IO [Int]
readIntList = do
    line <- B.getLine
    let res = map (fst . fromJust . B.readInt) $ B.words line
    return res

readString :: IO String
readString = do
    line <- B.getLine
    return $ filter (/= '\r') $ B.unpack line
    
getSumPerPos :: Int -> [Int] -> Seq.Seq Int
getSumPerPos cnt =  
    foldr step init
    where
        init = Seq.fromList $ replicate cnt 0
        step key seq = 
            let oldVal = Seq.index seq (key - 1)
            in
                Seq.update (key - 1) (oldVal + 1) seq

swap :: Seq.Seq a -> Int -> Int -> Seq.Seq a
swap seq p1 p2 = 
    let v1 = Seq.index seq p1
        v2 = Seq.index seq p2
        seq' = Seq.update p1 v2 seq
        seq'' = Seq.update p2 v1 seq'
    in
        seq''
         
getAns :: Seq.Seq Char -> Seq.Seq Int -> Int -> Int -> Int -> Seq.Seq Char
getAns str atPos low high acc 
    | low >= high = str
    | otherwise = 
        let acc' = Seq.index atPos low + acc
            str' = if acc' `mod` 2 == 0 then str else swap str low high 
        in
            getAns str' atPos (low + 1) (high - 1) acc'
        
          
main = do
    s <- readString
    m <- readInt
    ps <- readIntList
    let atPos = getSumPerPos (length s) ps
    let ans = toList $ getAns (Seq.fromList s) atPos 0 (length s - 1) 0
    putStrLn ans