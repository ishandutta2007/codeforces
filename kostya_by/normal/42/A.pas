program project1;

var
   a,b:array[1..21] of longint;
   i,n,v:longint;
   ans,x,xmin:extended;
begin
     readln(n,v);
     for i:=1 to n do read(a[i]);
     for i:=1 to n do read(b[i]);
     xmin:=maxlongint;
     for i:=1 to n do begin
         x:=b[i]/a[i];
         if x<xmin then xmin:=x;
     end;
     ans:=0;
     for i:=1 to n do begin
         ans:=ans+(a[i]*xmin);
     end;
     if ans>v then ans:=v;
     writeln(ans:1:5);
end.