var tt,i,n,j,t,t1,i1:longint;a:array[0..5000000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
  readln(tt);
  for i:=1 to tt do
  begin
    readln(n);
    for j:=1 to n do read(a[j]);
    sort(1,n);
    t:=0;t1:=0;                    
    for i1:=1 to n do
    begin
      inc(t1);
      if t1=a[i1] then
      begin
        inc(t);
        t1:=0;
      end;
    end;
    writeln(t);
  end;
end.