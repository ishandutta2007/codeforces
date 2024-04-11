import math
ans = int(input())
while ans >= 10:
    newans = 0
    for i in str(ans):
        newans += ord(i) - ord('0')
    ans = newans
print(ans)