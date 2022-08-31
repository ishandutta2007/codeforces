def f():
    return input().lower().replace('0','o').replace('1','l').replace('i','l')

a = f()
n = int(input())
ok = True
for i in range(n):
    if f() == a:
        ok = False
if ok:
    print("Yes")
else:
    print("No")