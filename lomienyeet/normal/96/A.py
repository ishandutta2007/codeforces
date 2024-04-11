s=input()
cnt=0
for i in range(len(s)-6):
    for j in range(i+1,i+7):
        if s[j]!=s[i]:
            break
    else:
        print("YES")
        cnt=1
    if bool(cnt):
        break
else:
    print("NO")