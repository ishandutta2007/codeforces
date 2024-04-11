def solve():
    n=int(input());

    ret=0;

    for i in range(n):
        ret=ret*2+1;

    return ret;

t=int(input());

while(t):
    t=t-1;

    print(solve());