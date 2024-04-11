calc :: Int -> Int -> Int -> Int
calc 0 d m = d - 1
calc n d m
    | d `mod` m == 0 = calc n (d + 1) m
    | otherwise = calc (n - 1) (d + 1) m

main = do
    line <- getLine
    let ns = map read (words line) :: [Int]
    print $ calc (ns !! 0) 1 (ns !! 1)