var
  n, k: Int64;

function Power2(N: Int64): Int64;
var
  i: Int64;
begin
  i := 1;
  While True do
  begin
    If i <= N then i := i*2 else Break;
  end;
  Result := i;
end;

begin
  Read(n, k);
  ReadLn;
  If k = 1 then WriteLn(n) else WriteLn(Power2(n)-1);
end.