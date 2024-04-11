s = input()
res = eval(s)
n = len(s)
for i in range(-1, n):
    if i == -1 or s[i] == '*':
        for j in range(i + 1, n + 1):
            if j == n or s[j] == '*':
                new_s = s[0:i + 1] + "(" + s[i + 1:j] + ")" + s[j:n]
                res = max(res, eval(new_s))
print(res)