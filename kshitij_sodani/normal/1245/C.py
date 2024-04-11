import sys
input=sys.stdin.readline
mod=10**9+7
dp=[1,2,3]
for i in range(10**5):
    dp.append(dp[-2]+dp[-1])
    dp[-1]%=mod
s=input()
n=len(s)
ind=0
cur=""
x=0
tot=1
st=True
while ind<n:
  #  print(cur)
    if s[ind]=="u":

        if cur=="n":
            tot*=dp[x-1]
            tot%=mod
            cur=""
            x=0
        if cur=="":
            cur="u"
        x+=1
        
    elif s[ind]=="n":
        if cur=="u":
            tot*=dp[x-1]
            tot%=mod
            cur=""
            x=0
        if cur=="":
            cur="n"
        x+=1
    else:
        if cur!="":
            tot*=dp[x-1]
            tot%=mod
            cur=""
            x=0
    if s[ind]=="w" or s[ind]=="m":
        st=False
    ind+=1
if cur!="":
    tot*=dp[x-1]
    tot%=mod
if st:
    print(tot)
else:
    print(0)