n = str(eval(input().strip()))
res = ''
for c in n:
    a = ord(c)
    res += "+" * a + ".[-]"
print(res)