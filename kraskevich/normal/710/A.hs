main = interact $ show . g

g (x:y:_)
  | [x, y] == "a1" || [x, y] == "a8" || [x, y] == "h1" || [x, y] == "h8" = 3
  | x == 'a' || x == 'h' || y == '1' || y == '8' = 5
  | otherwise = 8