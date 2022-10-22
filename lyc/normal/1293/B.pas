var n,i:longint;ans:double;
begin
  readln(n);
  for i:=n downto 1 do ans:=ans+1/i;
  writeln(ans:0:12);
end.