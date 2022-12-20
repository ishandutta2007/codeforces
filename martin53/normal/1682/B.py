def solve():
    n=int(input());

    inp=list(map(int,input().split(' ')));

    x=0;

    pwr=2**19;

    while pwr:

        if x+pwr<n:

            x=x+pwr;

            ok=True;

            for i in range(0,n):
                if (inp[i]&x)!=x and inp[i]!=i:
                    ok=False;

            if ok==False:
                x=x-pwr;

        pwr=pwr//2;

    return x;

t=int(input());

while t:
    t=t-1;

    print(solve());