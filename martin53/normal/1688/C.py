import sys

input = sys.stdin.readline

def solve():
    seen=[0]*26;

    n=int(input());

    for i in range(2*n+1):
        cur=input().rstrip();

        for j in cur:
            seen[ord(j)-ord('a')]=seen[ord(j)-ord('a')]+1;

    for i in range(26):
        if seen[i]%2==1:

            print(chr(i+ord('a')));

t=int(input());

while t:
    t=t-1;
    solve();