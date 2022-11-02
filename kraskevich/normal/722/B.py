cons = {'a', 'e', 'i', 'o', 'u', 'y'}

def cnt(s):
    res = 0
    for c in s:
        if c in cons:
            res += 1
    return res

n = int(input().strip())
ps = list(map(int, input().strip().split(' ')))
ok = True
for i in range(n):
    word = input().strip()
    if cnt(word) != ps[i]:
        ok = False 
print('YES' if ok else 'NO')