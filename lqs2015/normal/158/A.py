import functools
def cmp(x,y):
    if x > y :
        return -1
    else : 
        return 1
n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
a.sort(key = functools.cmp_to_key(cmp))
ans = 0
for i in range(n):
    if a[i] >= max(a[k-1], 1) :
        ans += 1
print(ans)