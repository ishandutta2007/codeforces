class solver_1684D:

    def __init__(self):
        self.n,self.k=list(map(int,input().split(' ')));
        self.inp=list(map(int,input().split(' ')));

    def solve(self):
        order=[];

        for i in range(0,self.n):
            order.append([self.inp[i]+i,i]);

        order.sort();

        skip=[0 for _ in range(0,self.n)];

        for i in range(self.k):
            skip[order[self.n-1-i][1]]=1;

        outp=0;
        skipped=0;

        for i in range(self.n):
            if skip[i]:
                skipped=skipped+1;
            else:
                outp=outp+self.inp[i]+skipped;

        return outp;

t=int(input());

while t:
    t=t-1;

    cur=solver_1684D();

    print(cur.solve());