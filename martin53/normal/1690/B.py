class solver:

    def __init__(self,n,a,b):
        self.a=a;
        self.b=b;
        self.n=n;

    def solve(self):
        low=0;
        high=10**9;

        for i in range(0,n):
            if b[i]==0:
                low=max(low,a[i]);
            elif low>a[i]-b[i] or a[i]-b[i]>high:
                print("NO");
                return;
            else:
                low=a[i]-b[i];
                high=low;

        if low>high:
            print("NO");
        else:
            print("YES");


t=int(input());

while t:
    t=t-1;

    n=int(input());

    a=list(map(int,input().split(' ')));
    b=list(map(int,input().split(' ')));

    cur=solver(n,a,b);

    cur.solve();