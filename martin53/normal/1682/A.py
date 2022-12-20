def solve():
    n=int(input());

    inp=input();

    l=n//2;
    r=n//2;

    while 0<=l and inp[l]==inp[n//2]:
        l=l-1;

    while r<n and inp[r]==inp[n//2]:
        r=r+1;

    return r-l-1;

t=int(input());

while t:
    t=t-1;

    print(solve());