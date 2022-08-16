#list(map(int,input().split()))
import sys
input=sys.stdin.readline
n=int(input())
it=list(map(int,input().split()))
s={}
for i in range(n):
    try:
        x=s[i-it[i]]
        s[i-it[i]]+=it[i]
    except:
        s[i-it[i]]=it[i]
print(max(s.values()))