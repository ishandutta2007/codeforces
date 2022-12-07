x = input()
l = len(x)
t = ["a","e","i","o","u","y","A","E","I","O","U","Y"]
ans = ""
i = 0
while i <= len(x) - 1:
    if x[i] not in t:
        if x[i].islower() is True:
            ans = str(ans) + "." + str(x[i])
        else :
            ans = str(ans) + "." + str(x[i].lower())
    else :
        ans = str(ans)
    i = i + 1
print(ans)