def solve():
    n,s=input().split();

    n=int(n);
    s=int(s);

    return s//n//n;

t=int(input());

while t:
    t=t-1;

    print(solve());