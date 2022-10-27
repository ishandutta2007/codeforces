ntest=int(input())
while ntest>0:
    ntest=ntest-1
    n=int(input())
    s1=input()
    s2=input()
    v=[]
    for i in range(n):
        if (s1[i] != s2[i]):
            v.append([s1[i], s2[i]])
    if (len(v)!=2 and len(v)!=0):
        print("No")
    elif (len(v)==2):
        if v[0][0] == v[1][0] and v[0][1]==v[1][1]:
            print("Yes")
        else:
            print("No")
    else:
        print("Yes")