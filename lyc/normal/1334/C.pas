uses math;
var t,i1,i,n:longint;s,s1,s2,s3:int64;a,b:array[0..300005]of int64;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n);s:=0;s1:=0;s2:=2000000000000;s3:=-1;
    read(a[1],b[1]);
    s:=s+a[1];
    for i:=2 to n do
    begin
      read(a[i],b[i]);
      s:=s+a[i];
      s1:=s1+min(b[i-1],a[i]);
      s2:=min(s2,min(b[i-1],a[i]));
    end;
    s1:=s1+min(b[n],a[1]);
    s2:=min(s2,min(b[n],a[1]));
    writeln(s-s1+s2);
  end;
end.