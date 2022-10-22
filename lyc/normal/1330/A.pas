uses math;
var t,n,x,i1,ans,i:longint;b,a:array[0..1000]of longint;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n,x);ans:=-1;
    fillchar(b,sizeof(b),0);
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
    begin
      read(a[i]);
      b[a[i]]:=1;
    end;
    for i:=1 to 300 do
    begin
      b[i]:=b[i]+b[i-1];
      if b[i]+x>=i then ans:=max(ans,i);
    end;
    writeln(ans);
  end;
end.