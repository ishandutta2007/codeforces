main = do
    line <- getLine
    let coords = map read (words line) :: [Int]
    let x1 = coords !! 0
    let y1 = coords !! 1
    let x2 = coords !! 2
    let y2 = coords !! 3
    putStrLn $ solve x1 y1 x2 y2
    where solve x1 y1 x2 y2 =  let dx = abs (x1 - x2)
                                   dy = abs (y1 - y2)
                               in case (dx, dy) of
                                   (0, d) -> show (x1 + d) ++ " " ++ show y1 ++ " "++ show (x1 + d) ++ " " ++ show y2
                                   (d, 0) -> show x1 ++ " " ++ show (y1 + d) ++ " " ++ show x2 ++ " " ++ show (y2 + d)
                                   (d1, d2) -> if d1 == d2
                                    then show x1 ++ " " ++ show y2 ++ " " ++ show x2 ++ " " ++ show y1
                                    else "-1"