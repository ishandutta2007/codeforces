# Author: lizi
# Email: lzy960601@outlook.com

import sys
import math

n = int(input())
ans = []
for i in range(min(n,100)):
    p = n - i
    s = p
    while p > 0:
        s += p % 10
        p = p // 10
    #print(s,' ',p)
    if s == n:
        ans.append( n - i );
print(len(ans))
ans.sort()
for x in ans:
    print(x)