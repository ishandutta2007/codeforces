n = int(raw_input())
cn = 0
cp = 0
for i in range(n):
    x,y = map(int, raw_input().split())
    if x<0: cn += 1
    else: cp += 1
print (cn<=1 or cp<=1) * "YES" or "NO"