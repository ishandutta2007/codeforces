l = input()
x = []
for i in range(len(l)):
    a = l[i]
    if a.islower() is True:
        x.append(a)
y = list(set(x))
print(len(y))