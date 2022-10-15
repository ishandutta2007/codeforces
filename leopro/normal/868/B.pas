program project1;

var
  h, m, s, t1, t2: SmallInt;

function IsBetween(Hand, t1, t2: SmallInt): Boolean;
begin
  Result := False;
  If (t1 > Hand) and (Hand > t2) and (t1 > t2) then Result := True;
  If (t2 > Hand) and (Hand > t1) and (t2 > t1) then Result := True;
end;

begin
  Read(h); Read(m); Read(s); Read(t1); ReadLn(t2);
  h := h mod 12;  t1 := t1 mod 12;    t2 := t2 mod 12;
  h := h*10+1;    t1 := t1*10;      t2 := t2*10;
  s := s*2;    m := m*2 + 1;
  If((not IsBetween(h,t1,t2))and(not IsBetween(m,t1,t2))and(not IsBetween(s,t1,t2)))
  or ((IsBetween(h,t1,t2)) and (IsBetween(m,t1,t2)) and (IsBetween(s,t1,t2))) then
  WriteLn('YES') else WriteLn('NO'); 
end.