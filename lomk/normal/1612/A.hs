import Control.Monad (replicateM)

main = do
  x <- getLine
  let nLines :: Int
      nLines = read x
  lines <- replicateM nLines getLine
  let res = map solve lines
  putStr $ unlines res

solve line = do
  let arr = [read x :: Int | x <- words line]
  let (x : y : _) = arr
  if (x + y) `mod` 2 == 1
    then "-1 -1"
    else unwords $ map show [floor $ fromIntegral x / 2, floor $ fromIntegral (y + 1) / 2]