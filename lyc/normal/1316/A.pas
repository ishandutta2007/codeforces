var t,i1,n,m,s,ans,x,i:longint;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n,m);s:=0;read(ans);
    for i:=2 to n do
    begin
      read(x);
      s:=s+x;
    end;
    if s+ans>m then writeln(m) else writeln(s+ans);
  end;
end.