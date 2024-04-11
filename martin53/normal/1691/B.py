class solver_1691B:

    def __init__(self):
        self.n=int(input());
        self.inp=list(map(int,input().split(' ')));

    def solve(self):

        outp=[];

        i=0;

        while i<self.n:
            j=i;

            while j<self.n and self.inp[i]==self.inp[j]:
                j=j+1;

            j=j-1;

            if i==j:
                print("-1");
                return;

            outp.append(j);

            for k in range(i,j):
                outp.append(k);

            i=j+1;

        for i in outp:
            print(i+1,end=' ');

        print();

t=int(input());

while t:

    t=t-1;

    cur=solver_1691B();

    cur.solve();