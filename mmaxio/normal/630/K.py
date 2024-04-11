n = int(input())

neg = [2, 3, 5, 7, 2*3*5, 2*3*7, 2*5*7, 3*5*7]
pos = [1, 2*3, 2*5, 2*7, 3*5, 3*7, 5*7, 2*3*5*7]

ret = 0
for x in neg:
    ret -= n // x
    
for x in pos:
    ret += n // x
    
print(ret)