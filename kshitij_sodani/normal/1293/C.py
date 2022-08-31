import sys
input=sys.stdin.readline
n,q=map(int,input().split())
st=[[0,0] for i in range(n)]
aa=set()
bb=set()
cc=set()
for i in range(q):
    b,a=map(int,input().split())
    if st[a-1][b-1]==1:
        if a>1:
            if b==1:
                if st[a-2][1]==1:
                    aa.remove(a)
            else:
                if st[a-2][0]==1:
                    bb.remove(a)
        if st[a-1][2-b]==1:
            cc.remove(a)
        if a<n:
            if b==2:
                if st[a][0]==1:
                    aa.remove(a+1)
            else:
                if st[a][1]==1:
                    bb.remove(a+1)
        if len(aa)==0 and len(bb)==0 and len(cc)==0:
            print("YES")
        else:
            print("NO")
    else:
        if a>1:
            if b==1:
                if st[a-2][1]==1:
                    aa.add(a)
            else:
                if st[a-2][0]==1:
                    bb.add(a)
        if st[a-1][2-b]==1:
            cc.add(a)
        if a<n:
            if b==2:
                if st[a][0]==1:
                    aa.add(a+1)
            else:
                if st[a][1]==1:
                   bb.add(a+1)
        if len(aa)==0 and len(bb)==0 and len(cc)==0:
            print("YES")
        else:
            print("NO")
    st[a-1][b-1]=1-st[a-1][b-1]