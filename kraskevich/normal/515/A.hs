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
    return $ B.unpack line

main = do
    [a, b, s] <- readIntList
    let dist = abs(a) + abs(b)
    let ans = if dist <= s && (s - dist) `mod` 2 == 0 then "Yes" else "No"
    putStrLn $ ans