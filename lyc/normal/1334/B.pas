uses math;
var t,i1,n,k,i:longint;sum:int64;a:array[0..200000]of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
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
  read(t);
  for i1:=1 to t do
  begin
    read(n,k);sum:=0;
    for i:=1 to n do
    begin
      read(a[i]);
    end;
    sort(1,n);
    for i:=1 to n+1 do
    begin
      if i=n+1 then break;
      sum:=sum+a[i]-k;
      if sum<0 then break;
    end;
    writeln(i-1);
  end;
end.