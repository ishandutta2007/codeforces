k = int(input())
s = input()
t = input()
val = [0 for i in range(0, k)]
nval = [0 for i in range(0, k)]
for i in range(0, k):
    val[i] = ord(s[i]) - ord('a') + ord(t[i]) - ord('a')
ans = ['a' for i in range(0, k)]
carry = 0
for i in range(0, k):
    ncarry = 0
    t = val[i] // 2 + carry
    if val[i] % 2 == 1:
        ncarry += 13
    nval[i] = t
    carry = ncarry
for i in range(k - 1, -1, -1):
    if nval[i] >= 26:
        nval[i - 1] += nval[i] // 26
        nval[i] %= 26
    ans[i] = chr(ord('a') + nval[i])
print("".join(x for x in ans))