a = input()
b = input()
x = ""
for i in range(len(a)):
    if a[i] == b[i]:
        x += "0"
    else:
        x += "1"
print(str(x))