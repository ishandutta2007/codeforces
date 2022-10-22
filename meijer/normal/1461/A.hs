
solve :: [Int] -> String
solve (x:y:_) = take x $ cycle "abc"

main :: IO ()
main = interact $ unlines . map solve . map (map read) . map words . tail . lines