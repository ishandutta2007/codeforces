n = input()
s = input()
print( 2 * (min(s.count('L'),s.count('R')) + min(s.count('U'), s.count('D'))))