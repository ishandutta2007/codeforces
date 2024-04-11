main = do
  s <- getLine
  let ns = words s
      n = read (ns !! 0) :: Integer
      c1 = read (ns !! 1) :: Integer
      c2 = read (ns !! 2) :: Integer

  s <- getLine
  let adults = (toInteger . length . filter (\t -> t == '1')) s
      total = (toInteger . length) s

  let cost x = c1 + c2 * (x - 1) ^ 2

  let f ngroups = let mingroup = (total `div` ngroups) :: Integer
                      cntmax   = (total `mod` ngroups) :: Integer
                  in (ngroups - cntmax) * (cost mingroup) + cntmax * (cost (mingroup + 1))

  putStrLn (show $ (foldl1 min) $ map f [1..adults])