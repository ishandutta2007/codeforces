s = input()
s = "0+1*" + s + "*1+0"
n = len(s)
ans = eval(s)
p = []
for i in range(0, n):
    if s[i] == '*':
        p.append(i)
for i in p:
    for j in p:
        if i >= j:
            continue
        if s[i] == '*' and s[j] == '*':
            t = s[:i+1] + "(" + s[i+1:j] + ")" + s[j:]
            res = eval(t)
            if res > ans:
                ans = res
print(ans)