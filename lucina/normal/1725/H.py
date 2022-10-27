'''
0 0 0
0 1 1
0 2 1
1 2 2
1 1 2
2 2 2

0 x1 x2
1 y1 y2
2 z1 z2 

Case 0: 012 12
Case 2: 0 1     0 2    0 120'''

a = int(input())
x = [int(i) for i in input().split()]
k = 0
for i in x:
    if i%3 == 0: 
        k += 1
if k >= a//2:
    print(2)
    t = a//2
    s = ""
    for i in x:
        if i%3 == 0 and t > 0:
            s += "0"
            t -= 1
        else:
            s += "1"
    print(s)
else:
    print(0)
    t = a//2
    s = ""
    for i in x:
        if i%3 != 0 and t > 0:
            s += "0"
            t -= 1
        else:
            s += "1"
    print(s)