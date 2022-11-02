import math

M,R = map(int,raw_input().split())

Sum = 0
for i in xrange(1,M+1):
    Sum += 2
    if i > 1:
        Sum += 1+math.sqrt(2)+1
        Sum += (2*math.sqrt(2)+1)*(i-2)
        Sum += (i-2)**2
    if i < M:
        Sum += 1+math.sqrt(2)+1
        Sum += (2*math.sqrt(2)+1)*(M-i-1)
        Sum += (M-i-1)**2
        
Sum = Sum*R/float(M**2)
print Sum