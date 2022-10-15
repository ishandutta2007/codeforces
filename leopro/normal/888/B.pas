program Project1;

var
  n, i: SmallInt;
  c: char;
  U, D, L, R: SmallInt;

begin
  ReadLn(n);
  U := 0; D := 0; L := 0; R := 0;
  For i := 1 to n do
  begin
    If i < n then Read(c) else ReadLn(c);
    Case ord(c) of
      68: D := D+1;
      76: L := L+1;
      82: R := R+1;
      85: U := U+1;
    end;
  end;
  If D > U then D := U;
  If R > L then R := L;
  WriteLn(D+R+D+R); 
end.