def solve():
    n=int(input());

    inp = list(map(int, input().split(' ')))

    inp.sort();

    outp=[];

    if n%2==1:
        print("NO");
        return;

    for i in range(0,n):
        if i%2==0:
            outp.append(inp[i//2]);
        else:
            outp.append(inp[n//2+i//2]);

    for i in range(0,n):
        if outp[i]==outp[(i+1)%n]:
            print("NO");
            return;

    print("YES");

    print(' '.join(map(str,outp)));

t=int(input());

while t:
    t=t-1;
    solve();