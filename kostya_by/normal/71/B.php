<?php
class INPUT_HELP{
    public function read_array(){
        $a[0] = '';
        $j = 0;
        $input = fgets(STDIN);
        for ($i = 0; $i < strlen($input); $i++){
            if (preg_replace("/[0-9A-z-._-]/",null,$input[$i]) == false) {
                $a[$j] = $a[$j].$input[$i];
            } else {
                if ($a[$j] != '') {
                    ++$j;
                    $a[$j] = '';
                }
            }
        }
        return $a;
    }
    public function read_one(){
        $array = $this->read_array();
        return $array[0];
    }
}
?>
<?php
    $input_connect = new INPUT_HELP();
    $a = $input_connect->read_array();
    $n = $a[0];
    $k = $a[1];
    $t = $a[2];
    $sum = floor(($n * $k * $t) / 100);
    for ($i = 0; $i < $n; $i++){
        if ($sum == 0) echo '0 ';
        if ($sum < $k && $sum > 0) {
            echo $sum.' ';
            $sum = 0;
        };
        if ($sum >= $k) {
            echo $k.' ';
            $sum -= $k;
        }
    }
?>