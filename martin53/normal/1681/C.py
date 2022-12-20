class solver_1681C:

    def __init__(self):
        self.n=int(input());
        self.a=list(map(int,input().split(' ')));
        self.b=list(map(int,input().split(' ')));

    def solve(self):
        outp=[];

        for i in range(0,self.n):
            for j in range(i+1,self.n):
                if self.a[i] > self.a[j]:

                    temp=self.a[i];
                    self.a[i]=self.a[j];
                    self.a[j]=temp;

                    temp=self.b[i];
                    self.b[i]=self.b[j];
                    self.b[j]=temp;

                    outp.append([i,j]);

        for i in range(0, self.n):
            for j in range(i + 1, self.n):
                if self.a[i] == self.a[j] and self.b[i] > self.b[j]:
                    temp = self.a[i];
                    self.a[i] = self.a[j];
                    self.a[j] = temp;

                    temp = self.b[i];
                    self.b[i] = self.b[j];
                    self.b[j] = temp;

                    outp.append([i, j]);

        for i in range(1,self.n):
            if self.a[i-1]>self.a[i] or self.b[i-1]>self.b[i]:
                print("-1");
                return;

        print(len(outp));

        for i in range(len(outp)):
            print(outp[i][0]+1,outp[i][1]+1);


t=int(input());

while t:
    t=t-1;

    cur=solver_1681C();

    cur.solve();