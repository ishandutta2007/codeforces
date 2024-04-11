class solver:

    def __init__(self, n):
        self.n=n;

    def solve(self):
        h1=(self.n+5)//3;
        h2=h1-1;
        h3=n-h1-h2;

        if h3<=0:
            h3=1;
            h2=n-h1-h3;

        print(h2,h1,h3);



t=int(input());

while t:
    t=t-1;

    n=int(input());

    cur=solver(n);

    cur.solve();