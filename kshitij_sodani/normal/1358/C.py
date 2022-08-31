t=int(input())
for _ in range(t):
    a,b,c,d=map(int,input().split())
    if(a==c or b==d):
        print(1)
        continue
    mi=((c-a)*(c-a+1))//2
    st=((c-a)+(d-b))
    end=((d-b+1))
    ma=((end+st)*(st-end+1))//2
   # print(mi,ma)
    print(ma-mi+1)