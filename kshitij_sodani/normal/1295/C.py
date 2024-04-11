#import sys
#input=sys.stdin.readline
from bisect import *
tt=int(input())
for _ in range(tt):
    s=list(input())
    t=list(input())
    s=[ord(i)-97 for i in s]
    t=[ord(i)-97 for i in t]
    freq=[[] for i in range(26)]
    j=0
    for i in s:
        freq[i].append(j)
        j+=1
    freq2=[[] for i in range(26)]
    j=0
    for i in t:
        freq2[i].append(j)
        j+=1
    st=0
    for i in range(26):
        if freq[i]==[] and len(freq2[i])>0:
            st=1
            break
    if st:
        print(-1)
    else:
        ind=0
        ind2=0
        co=0
        while ind2<len(t):
            co+=1
            while ind2<len(t):
             #   print(ind2)
                x=bisect_left(freq[t[ind2]],ind)
                if x==len(freq[t[ind2]]):
                    ind=0
                    break
                ind2+=1
                ind=freq[t[ind2-1]][x]+1
        print(co)