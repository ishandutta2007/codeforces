for _ in range(int(input())):
    s=input()
    t=input()
    ss={}
    tt={}
    st=False
    for i in s:
        if i in t:
            st=True
    if st==True :
        print("YES")
    else:
        print("NO")