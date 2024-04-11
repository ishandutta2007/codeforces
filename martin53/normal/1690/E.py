class solve_1690E:

    def __init__(self):
        self.n,self.k=map(int,input().split(' '));
        self.inp=list(map(int,input().split(' ')));

    def solve(self):
        outp=0;

        for i in range(self.n):
            outp+=self.inp[i]//self.k;
            self.inp[i]=self.inp[i]%self.k;

        self.inp.sort();

        l=0;
        r=self.n-1;

        while l<r:
            if self.inp[l]+self.inp[r]>=self.k:
                l=l+1;
                r=r-1;
                outp=outp+1;
            else:
                l=l+1;

        return outp;


t=int(input());

while t:

    t=t-1;

    cur=solve_1690E();

    print(cur.solve());