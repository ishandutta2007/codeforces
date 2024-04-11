import Data.List

toint s = (read s) :: Integer

doit [] t = 0
doit (x:xs) t
    | mod x 3 == 0            = 1 + doit xs 0
    | t == 3                  = 1 + doit xs 0
    | mod x 3 == 1 && t == 0  = doit xs 1
    | mod x 3 == 1 && t == 1  = doit xs 3
    | mod x 3 == 1 && t == 2  = 1 + doit xs 0
    | mod x 3 == 2 && t == 0  = doit xs 2
    | mod x 3 == 2 && t == 1  = 1 + doit xs 0
    | mod x 3 == 2 && t == 2  = doit xs 3


solve::String -> String
solve ss =
    let d = map (\x -> toint [x]) (reverse (tail (reverse ss))) in
    let r = doit d 0 in
    (show r) ++ "\n"

main = do
  interact $ solve