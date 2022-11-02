a = ""
for i in range(8): 
    a += raw_input()
x = a.count('q')*9 + a.count('r')*5 + a.count('b')*3 + a.count('n')*3 + a.count('p') *1
y = a.count('Q')*9 + a.count('R')*5 + a.count('B')*3 + a.count('N')*3 + a.count('P') *1
print "White" if y > x else  "Black" if y < x else "Draw"