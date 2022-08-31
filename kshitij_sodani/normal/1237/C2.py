import sys
input=sys.stdin.readline
def d(le):
    for i in range(0,len(le),2):
    #    if le[i][3]==29 and le[i+1][3]==38:
     #       print(me)
      #      return ''
        print(le[i][3],le[i+1][3])
    
def dd(it):
    global do
   # print(it)
    tt={}
    ddd=[]
    it.sort(key=lambda x:x[1])
    l=list(set([i[1] for i in it]))
    l.sort()
    for i in l:
        tt[i]=[]
    for i in it:
        tt[i[1]].append(i)
    for i in l:
        x=tt[i]
        x.sort(key=lambda x:x[0])
        if len(x)%2==1:
            ddd.append(x[-1][:])
            x=x[:-1]
        if len(x)>0:
            
            d(x[:])
    ddd.sort(key=lambda x:x[1])
    if len(ddd)%2==1:
        do.append(ddd[-1][:])
        ddd=ddd[:-1]
    if len(ddd)>0:
        
        d(ddd)
n=int(input())
it=[]
for i in range(n):
    it.append(list(map(int,input().split()))+[i+1])
ss={}
it.sort(key=lambda x:x[2])
l=list(set([i[2] for i in it]))
l.sort()
for i in l:
    ss[i]=[]
for i in it:
    ss[i[2]].append(i)
do=[]
for i in l:
    x=ss[i]
    dd(x[:])
do.sort(key=lambda x:x[2])
d(do)