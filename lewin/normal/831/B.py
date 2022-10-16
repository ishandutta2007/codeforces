a = raw_input()
b = raw_input()

s = raw_input()
t = ""
for x in s:
    upper = False
    if ord(x) >= ord('A') and ord(x) <= ord('Z'):
        upper = True
        x = chr(ord(x) - ord('A') + ord('a'))
    if x in a:
    	p = a.index(x)
    	y = b[p]
    else:
    	y = x
    if upper:
        y = chr(ord(y) - ord('a') + ord('A'))
    t += y
print t